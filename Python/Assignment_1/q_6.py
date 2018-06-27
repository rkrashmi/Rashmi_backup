choice = input("1.add 2.sub 3.mul 4.div 5.go back  :  ")
num1 = input("enter num1  :  ")
num2 = input("enter num2  :  ")

if choice == 1 :
    print num1 + num2

elif choice == 2 :
    print num1 - num2

elif choice == 3 :
    print num1 * num2

elif choice == 4 :
    print num1 / num2

else :
    print "exiting"
