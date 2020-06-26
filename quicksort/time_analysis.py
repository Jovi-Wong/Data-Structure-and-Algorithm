import matplotlib.pyplot as plt
import math
x1=[]
for i in range(1,120):
    x1.append(i*1000)
x=[]
y=[]
z=[]
with open("tmcsm.txt") as file:
    for content in file:
        a,b=content.split()
        x.append(int(a))
        y.append(int(b))

for i in x1:
    z.append(0.005*i*math.log(i,2))
plt.title("time complexity of quick sort")
plt.xlabel("length")
plt.ylabel("ms")
plt.xlim(0,120000)
plt.ylim(0,10000)
plt.plot(x,y,label="quick sort")
plt.plot(x1,z,label="y=0.005*x*log(x)")
plt.legend()
plt.show()