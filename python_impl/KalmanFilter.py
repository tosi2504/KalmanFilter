import numpy as np

def make_G(dt):
    result = np.zeros(shape=(6,3))
    for i in range(3):
        result[i,i] = 0.5 * dt**2
        result[i+3,i] = dt
    return result

def make_Q(G, Cov_acc):
    return G @ Cov_acc @ G.T

def make_F(dt):
    result = np.zeros(shape=(6,6))
    for i in range(6):
        result[i,i] = 1
    for i in range(3):
        result[i, i+3] = dt
    return result

class KalmanFilter3DPoint:
    def __init__(self, state_init, covariance_init):
        self.state = state_init
        self.covariance = covariance_init
        self.state_predict = None
        self.covariance_predict = None
        self.H = np.eye(N = 3, M = 6)
        self.I = np.identity(6)

    def time_update(self, dt, acc_measurement, Cov_acc):
        G = make_G(dt)
        Q = make_Q(G, Cov_acc)
        F = make_F(dt)
        self.state_predict = F @ self.state + G @ acc_measurement
        self.covariance_predict = F @ self.covariance @ F.T + Q

    def measurement_update(self, pos_measurement, Cov_pos):
        K = self.covariance_predict @ self.H.T @ np.linalg.inv(self.H @ self.covariance_predict @ self.H.T + Cov_pos)
        self.state = self.state_predict + K @ (pos_measurement - self.H @ self.state_predict)
        self.covariance = (self.I - K @ self.H) @ self.covariance_predict @ (self.I - K @ self.H).T + K @ Cov_pos @ K.T

    def weak_measurement_update(self):
        self.state = self.state_predict
        self.covariance = self.covariance_predict
