import numpy as np

xe =240.3185424949238
ye = 60
ze =56.568542494923804
l1= 63.75
l2=80
l3=120

if (np.sqrt(xe**2+ye**2+ze**2) <= l1 + l2 +l3) :
    if (ye != 0 and xe !=0):
        phi1 = np.arctan2(ye,xe)
    elif ye == 0 :
        phi1 = 0
    print("phi1 = ", np.degrees(phi1))

    p1 = [np.cos(phi1)*l1, l1*np.sin(phi1), 0]
    r = np.sqrt((xe-p1[0])**2+(ye-p1[1])**2+(ze-p1[2])**2)
   # print(r)

    theta3 = np.arccos((-l3**2+l2**2+(r)**2)/(2*l2*(r)))-np.arcsin((p1[2]-ze)/(r))
    print ("theta3 = ", np.degrees(theta3))

    theta34 = - np.pi  + np.arccos((-r**2+l2**2+l3**2)/(2*l2*l3))
    print("theta 4 = ",(-r**2+l2**2+l3**2)/(2*l2*l3))
    print("theta 34 = ", np.degrees(theta34))


else :
    print ("Não alcançável")