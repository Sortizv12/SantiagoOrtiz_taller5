import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation
u=np.genfromtxt("datos.txt")[1:]
x=np.genfromtxt("datos.txt")[0]
"""
Matplotlib Animation Example

author: Jake Vanderplas
email: vanderplas@astro.washington.edu
website: http://jakevdp.github.com
license: BSD
Please feel free to use and modify this, but keep the above information. Thanks!
"""
# First set up the figure, the axis, and the plot element we want to animate
fig = plt.figure()
ax = plt.axes(xlim=(0, 100), ylim=(-1, 1))
line, = ax.plot([], [], lw=2)

# initialization function: plot the background of each frame
def init():
	line.set_data([], [])
	return line,

# animation function.  This is called sequentially
def animate(i):
	y=u
	line.set_data(x, y)
	return line,

# call the animator.  blit=True means only re-draw the parts that have changed.
anim = animation.FuncAnimation(fig, animate, init_func=init,
                               frames=200, interval=20, blit=True)
plt.show()
anim.save('cuerda.gif', writer='imagemagick', fps=60)# fps=30)#, extra_args=['-vcodec', 'libx264'])


