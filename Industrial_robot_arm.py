"""
Industrial Robot - 2 DOF Forward Kinematics
Field: Industrial Engineering and Robotics
Specialization: Computerized Engineering
"""

import math

# Robot parameters (meters)
L1 = 0.8   # length of first arm
L2 = 0.6   # length of second arm

# Joint angles (degrees)
theta1 = 30
theta2 = 45

# Convert degrees to radians
t1 = math.radians(theta1)
t2 = math.radians(theta2)

# Forward kinematics equations
x = L1 * math.cos(t1) + L2 * math.cos(t1 + t2)
y = L1 * math.sin(t1) + L2 * math.sin(t1 + t2)

print("End-effector position:")
print(f"x = {x:.2f} m")
print(f"y = {y:.2f} m")
