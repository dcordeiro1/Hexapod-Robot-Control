import numpy as np
import matplotlib.pyplot as plt

l1= 63.75
l2=80
l3=120

fig = plt.figure(1)
ax = plt.axes(projection ="3d",title= 'Hexapod´s Workspace', xlabel= 'X axis (mm)', ylabel= 'Y axis (mm)', zlabel= 'Z axis (mm)')

for phi1 in np.arange (-35,35,5,dtype=int):
    for theta3 in np.arange (-85,85,5,dtype=int):
        for theta34 in np.arange (-85,85,5,dtype=int):
            phi1r=np.radians(phi1)
            theta3r=np.radians(theta3)
            theta4r=np.radians(theta34)+theta3r
            x = np.cos(phi1r)*(l3*np.cos(theta4r)+l2*np.cos(theta3r)+l1)
            y = np.sin(phi1r)*(l3*np.cos(theta4r)+l2*np.cos(theta3r)+l1)
            z = l3*np.sin(theta4r) + l2* np.sin (theta3r)
            ax.scatter3D(x, y, z, color="red", alpha=0.05)

#Draw robot

phi1_l = np.radians(0)
theta3_l = np.radians(45)
theta4_l = np.radians(-85)+theta3_l
p0 = [0, 0, 0]
p1 = [np.cos(phi1_l)*l1, l1*np.sin(phi1_l), 0]
p2 = [np.cos(phi1_l)*(l1 + np.cos(theta3_l)*l2), (l1+l2*np.cos(theta3_l))*np.sin(phi1_l), l2*np.sin(theta3_l)]
p3 = [np.cos(phi1_l)*(l3*np.cos(theta3_l+theta4_l)+l2*np.cos(theta3_l)+l1),
      np.sin(phi1_l)*(l3*np.cos(theta3_l+theta4_l)+l2*np.cos(theta3_l)+l1),
      l3*np.sin(theta3_l+theta4_l) + l2* np.sin (theta3_l)]
ax.plot([p0[0], p1[0]], [p0[1], p1[1]], [p0[2], p1[2]], 'o-', c = 'blue')
ax.plot([p1[0], p2[0]], [p1[1], p2[1]], [p1[2], p2[2]], 'o-', c = 'blue')
ax.plot([p2[0], p3[0]], [p2[1], p3[1]], [p2[2], p3[2]], 'o-', c = 'green')
plt.show()
