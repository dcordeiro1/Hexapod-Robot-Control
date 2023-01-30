import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure(1)
ax = plt.axes(projection ="3d",title= 'Bezier Curve', xlabel= 'X axis (mm)', ylabel= 'y axis (mm)',zlabel= 'Z axis (mm)')
ax.set_xlim([-50,200])
ax.set_ylim([-160,160])
ax.set_zlim([-130,130])

#P0=[100,-100,-130]
#P1=[100,0,20]
#P2=[100,100,-130]
#P3=[100,-100,-130]

# ----------------n=5
# xe = (1 - i) ** 5 * P0[0] + 5 * i * (1 - i) ** 4 * P1[0] + 10 * i ** 2 * (1 - i) ** 3 * P2[0] + 10 * i ** 3 * (1 - i) ** 2 * P3[0] + 5 * i ** 4 * (1 - i) * P4[0] + i ** 5 * P5[0]
# ye = (1 - i) ** 5 * P0[1] + 5 * i * (1 - i) ** 4 * P1[1] + 10 * i ** 2 * (1 - i) ** 3 * P2[1] + 10 * i ** 3 * (1 - i) ** 2 * P3[1] + 5 * i ** 4 * (1 - i) * P4[1] + i ** 5 * P5[1]
# ze = (1 - i) ** 5 * P0[2] + 5 * i * (1 - i) ** 4 * P1[2] + 10 * i ** 2 * (1 - i) ** 3 * P2[2] + 10 * i ** 3 * (1 - i) ** 2 * P3[2] + 5 * i ** 4 * (1 - i) * P4[2] + i ** 5 * P5[2]
# ----------------n=3
# xe=(1 - i) ** 3 * P0[0] + 3 * (1 - i)**2 * i * P1[0] + 3 * (1-i) * i ** 2 * P2[0] + i**3 *P3[0]
# ye = (1 - i) ** 3 * P0[1] + 3 * (1 - i) ** 2 * i * P1[1] + 3 * (1 - i) * i ** 2 * P2[1] + i ** 3 * P3[1]
# ze = (1 - i) ** 3 * P0[2] + 3 * (1 - i) ** 2 * i * P1[2] + 3 * (1 - i) * i ** 2 * P2[2] + i ** 3 * P3[2]
#----------------n=2
#xe = (1 - t) ** 2 * P0[0] + 2 * (1 - t) * t * P1[0] + t ** 2 * P2[0]
#ye = (1 - t) ** 2 * P0[1] + 2 * (1 - t) * t * P1[1] + t ** 2 * P2[1]
#ze = (1 - t) ** 2 * P0[2] + 2 * (1 - t) * t * P1[2] + t ** 2 * P2[2]
'''P0=[100,-50,-130]
P1=[100,-100,-100]
P2=[100,0,20]
P3=[100,100,-100]
P4=[100,50,-130]
P5=[100,-50,-130]'''

posx=[]
posy=[]
posz=[]

for i in np.arange(0, 4, 0.01, dtype=float):
        #-------------n=2
    if (i>=0 and i<=1):
        t = i
        P0=[120,-60,-130]
        P1=[120,-40,-130]
        P2 = [120,-20, -130]
        P3=[120,0,-130]
        xe= (1 - t) ** 3 * P0[0] + 3 * (1 - t)**2 * t * P1[0] + 3 * (1-t) * t ** 2 * P2[0] + t**3 *P3[0]
        ye = (1 - t) ** 3 * P0[1] + 3 * (1 - t) ** 2 * t * P1[1] + 3 * (1 - t) * t ** 2 * P2[1] + t ** 3 * P3[1]
        ze = (1 - t) ** 3 * P0[2] + 3 * (1 - t) ** 2 * t * P1[2] + 3 * (1 - t) * t ** 2 * P2[2] + t ** 3 * P3[2]

    if (i >= 0 and i <= 1):
        t = i-1
        P0 = [120, 0, -130]
        P1 = [120, 20, -130]
        P2 = [120, 40, -130]
        P3 = [120, 60, -130]
        xe = (1 - t) ** 3 * P0[0] + 3 * (1 - t) ** 2 * t * P1[0] + 3 * (1 - t) * t ** 2 * P2[0] + t ** 3 * P3[0]
        ye = (1 - t) ** 3 * P0[1] + 3 * (1 - t) ** 2 * t * P1[1] + 3 * (1 - t) * t ** 2 * P2[1] + t ** 3 * P3[1]
        ze = (1 - t) ** 3 * P0[2] + 3 * (1 - t) ** 2 * t * P1[2] + 3 * (1 - t) * t ** 2 * P2[2] + t ** 3 * P3[2]
    if (i>2 and i<=3):
        t = i - 2
        P0 = [120, 70, -130]
        P1 = [120, 130, -100]
        P2 = [120, 50, 20]
        P3 = [120, 0, 20]
        xe = (1 - t) ** 3 * P0[0] + 3 * (1 - t) ** 2 * t * P1[0] + 3 * (1 - t) * t ** 2 * P2[0] + t ** 3 * P3[0]
        ye = (1 - t) ** 3 * P0[1] + 3 * (1 - t) ** 2 * t * P1[1] + 3 * (1 - t) * t ** 2 * P2[1] + t ** 3 * P3[1]
        ze = (1 - t) ** 3 * P0[2] + 3 * (1 - t) ** 2 * t * P1[2] + 3 * (1 - t) * t ** 2 * P2[2] + t ** 3 * P3[2]
    if (i>3 and i<=4):
        t = i - 3
        P0 = [120, 0, 20]
        P1 = [120,- 50, 20]
        P2 = [120, -130, -100]
        P3 = [120,-70,-130]
        xe = (1 - t) ** 3 * P0[0] + 3 * (1 - t) ** 2 * t * P1[0] + 3 * (1 - t) * t ** 2 * P2[0] + t ** 3 * P3[0]
        ye = (1 - t) ** 3 * P0[1] + 3 * (1 - t) ** 2 * t * P1[1] + 3 * (1 - t) * t ** 2 * P2[1] + t ** 3 * P3[1]
        ze = (1 - t) ** 3 * P0[2] + 3 * (1 - t) ** 2 * t * P1[2] + 3 * (1 - t) * t ** 2 * P2[2] + t ** 3 * P3[2]

    posx.append(xe)
    posy.append(ye)
    posz.append(ze)
    ax.scatter3D(xe, ye, ze, color="red")
    ax.plot(posx,posy,posz, color="orange")
    l1 = 63.75
    l2 = 80
    l3 = 120
    if (np.sqrt(xe ** 2 + ye ** 2 + ze ** 2) <= l1 + l2 + l3):
        if (ye != 0 and xe != 0):
            phi1 = np.arctan2(ye, xe)
        elif ye == 0:
            phi1 = 0
        #print("phi1 = ", np.degrees(phi1))

        p1 = [np.cos(phi1) * l1, l1 * np.sin(phi1), 0]
        r = np.sqrt((xe - p1[0]) ** 2 + (ye - p1[1]) ** 2 + (ze - p1[2]) ** 2)

        theta3 = np.arccos((-l3 ** 2 + l2 ** 2 + (r) ** 2) / (2 * l2 * (r))) - np.arcsin((p1[2] - ze) / (r))
        print("theta3 = ", np.degrees(theta3))

        theta34 = - np.pi + np.arccos((-r ** 2 + l2 ** 2 + l3 ** 2) / (2 * l2 * l3))
        #print("theta 34 = ", np.degrees(theta34))

        p_0 = [0, 0, 0]
        p_1 = [np.cos(phi1) * l1, l1 * np.sin(phi1), 0]
        p_2 = [np.cos(phi1) * (l1 + np.cos(theta3) * l2), (l1 + l2 * np.cos(theta3)) * np.sin(phi1),
               l2 * np.sin(theta3)]
        p_3 = [np.cos(phi1) * (l3 * np.cos(theta34 + theta3) + l2 * np.cos(theta3) + l1),
               np.sin(phi1) * (l3 * np.cos(theta34 + theta3) + l2 * np.cos(theta3) + l1),
               l3 * np.sin(theta34 + theta3) + l2 * np.sin(theta3)]
        ax.plot([p_0[0], p_1[0]], [p_0[1], p_1[1]], [p_0[2], p_1[2]], 'o-', c='blue')
        ax.plot([p_1[0], p_2[0]], [p_1[1], p_2[1]], [p_1[2], p_2[2]], 'o-', c='blue')
        ax.plot([p_2[0], p_3[0]], [p_2[1], p_3[1]], [p_2[2], p_3[2]], 'o-', c='green')

        plt.pause(0.1)

        ax.cla()
        ax.set_xlim([-50, 200])
        ax.set_ylim([-160, 160])
        ax.set_zlim([-130, 130])
    else:
        print("Não alcançável")


plt.show()
