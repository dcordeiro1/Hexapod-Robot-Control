import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure(1)
ax = plt.axes(projection ="3d",title= 'Bezier Curve', xlabel= 'X axis (mm)', ylabel= 'Z axis (mm)',zlabel= 'Z axis (mm)')

P0=[100,-100,-130]
P1=[100,0,20]
P2=[100,100,-130]
P3=[100,-100,-130]
for i in np.arange(0,1,0.1, dtype=float):
    x=(1-i)**3*P0[0]+3*(1-i)**2*i*P1[0]+i**2*P2[0]+i**3*P3[0]
    y=(1-i)**3*P0[1]+3*(1-i)**2*i*P1[1]+i**2*P2[1]+i**3*P3[1]
    z=(1-i)**3*P0[2]+3*(1-i)**2*i*P1[2]+i**2*P2[2]+i**3*P3[2]
    ax.scatter3D(x, y, z, color="red")
plt.show()
