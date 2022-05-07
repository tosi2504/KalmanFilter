from KalmanFilter import KalmanFilter3DPoint as KalmanFilter
import numpy as np
import scipy as sp
from math import sin, cos, pi, sqrt
import matplotlib.pyplot as plt


def create_measurements(poss_real, dt, pos_cov, acc_cov):
    vels_real = np.gradient(poss_real, axis = 0)/dt
    accs_real = np.gradient(vels_real, axis = 0)/dt
    poss_deviance = np.random.multivariate_normal(mean = [0,0,0], cov = pos_cov, size = len(poss_real))
    poss_measurement = poss_real + poss_deviance
    accs_measurement = accs_real + np.random.multivariate_normal(mean = [0,0,0], cov = acc_cov, size = len(poss_real))
    plt.hist(poss_deviance.T[0])
    plt.show()
    return poss_measurement, accs_measurement

def trajectory_one():
    poss = list()

    #straight line
    for i in range(200):
        poss.append([i/200,0,0])

    #half a circle afterwards
    R = 0.5
    phi_0 = 3/2 * pi
    phi_1 = 1/2 * pi
    N = 400
    dphi = (phi_0 - phi_1)/N
    for i in range(N):
        poss.append([1 + R*cos(phi_0 + i*dphi),R + R*sin(phi_0 + i*dphi),0])



    return np.array(poss)


sampling_acc = 100
sampling_gps = 20
dt = 1/sampling_acc
pos_measure_skip = sampling_acc // sampling_gps
# path and measurement creation
poss_real = trajectory_one()
sigma_pos = 0.017
sigma_acc = sqrt(sampling_acc)*0.001*0.14*9.81
pos_cov = np.array([[sigma_pos**2,0,0], [0,sigma_pos**2,0], [0,0,0.0000001]])
acc_cov = np.array([[sigma_acc**2,0,0], [0,sigma_acc**2,0], [0,0,0]])
poss_measurement, accs_measurement = create_measurements(poss_real, dt, pos_cov, acc_cov)

#kalman stuff
kf = KalmanFilter([0,0,0,0,0,0], np.identity(6))
pos_kf = list()
for i in range(600):
    kf.time_update(dt, accs_measurement[i], acc_cov)
    if i%pos_measure_skip == 0:
        kf.measurement_update(poss_measurement[i], pos_cov)
    else:
        kf.weak_measurement_update()
    pos_kf.append(kf.state[0:3])

pos_kf = np.array(pos_kf)

print(pos_kf)
print("Speed in linear segment: {1/(dt*200)} m/s")
print(f"Speed in half circle segment: {pi /(dt*400)} m/s")


plt.plot(poss_real.T[0], poss_real.T[1], color = "black", linewidth = 5)
plt.plot(poss_measurement.T[0][::pos_measure_skip], poss_measurement.T[1][::pos_measure_skip], color = "blue")
plt.plot(pos_kf.T[0], pos_kf.T[1], color="red")
plt.show()


T = np.concatenate((np.linspace(0,1,200), np.linspace(1,1+pi,400)))
dev = np.sqrt(((pos_kf - poss_real)**2).sum(axis = 1))
plt.plot(T, dev)
plt.show()
