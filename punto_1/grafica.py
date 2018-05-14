import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.gridspec as gridspec

x=np.genfromtxt("matriz.txt")[0]
V=np.genfromtxt("matriz.txt")[1:513]
Ex=np.genfromtxt("matriz.txt")[514:-511]
Ey=np.genfromtxt("matriz.txt")[-512:]
thing=np.sqrt(Ex*Ex + Ey*Ey)
lw = 4*thing/ thing.max()
plt.subplot(2,1,1)
plt.imshow(np.transpose(V),extent=(0,5,0,5))
plt.title("Potencial electrico en la region")
plt.subplot(2,1,2)
plt.streamplot(x,x,np.transpose(Ex),np.transpose(Ey),density=2,color=Ex,linewidth=lw, cmap="magma")
plt.title("Campo electrico en la region")
plt.savefig("placas.pdf")
