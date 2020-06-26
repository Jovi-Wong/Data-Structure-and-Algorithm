import matplotlib.pyplot as plt
l1, = plt.plot(x, y1, label='linear line')

l2, = plt.plot(x, y2, color='red', linewidth=1.0, linestyle='--', label='square line')

 

 

plt.legend(handles = [l1,l2],labels = ['up','down'],loc = 'best')

#the ',' is very important in here l1, = plt...and l2, = plt...for this step

"""legend( handles=(line1, line2, line3),

           labels=('label1', 'label2', 'label3'),

           'upper right')

    shadow = True 设置图例是否有阴影

    The *loc* location codes are::

          'best' : 0,         

          'upper right'  : 1,

          'upper left'   : 2,

          'lower left'   : 3,

          'lower right'  : 4,

          'right'        : 5,

          'center left'  : 6,

          'center right' : 7,

          'lower center' : 8,

          'upper center' : 9,

          'center'       : 10,"""