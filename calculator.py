import os

print("\n")
n1=int(input(' number1 = '))
n2=int(input(' number2 = '))
op=input('\n +, -, *, /, ** : ')
print("\nans:\n")

if op=='+':
    print(n1+n2)
elif op=='-':
    print(n1-n2)
elif op=='*':
    print(n1*n2)
elif op=='/':
    print(n1/n2)
elif op=='**':
    print(n1**n2)
else:
    print(' 不支援的運算')
os.system('pause')
