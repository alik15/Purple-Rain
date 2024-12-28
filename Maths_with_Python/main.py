

#outputs all the index values that are on
def isOn(list1):
    on = list()
    for i in list1:
        print(i)
        if list1[i] == 1:
            on.append(i)
    print(on)
            

#turns on the lights at multiples of the index
def turnOn(list1, index):
    
    for i in list1:
        if ((i%index)==0):
            
            if (list1[i]==0):
             list1[i]=1
            else:
                list1[i]=0
                
       
            
            
        
        


list1=list()

for i in range(100):
    
    list1.append(1)
    
    
for i in range(1,101):
    turnOn(list1,i)
    
    
list2=[1,1,1,1,1,0]
isOn(list2)

