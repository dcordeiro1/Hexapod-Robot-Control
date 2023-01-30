import numpy as np

l1= 63.75
l2=80
l3=120

phi1r = np.radians(-35)
theta3r = np.radians(45)
theta34r = np.radians(-45)
x = np.cos(phi1r)*(l3*np.cos(theta34r+theta3r)+l2*np.cos(theta3r)+l1)
y = np.sin(phi1r)*(l3*np.cos(theta34r+theta3r)+l2*np.sin(theta3r)+l1)
z = l3*np.sin(theta34r+theta3r) + l2* np.sin (theta3r)


print("Posição end-effector x;y;z:",x,y,z)
