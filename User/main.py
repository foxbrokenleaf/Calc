key = 1
for temp in range(4):
    counter = 1
    while counter <= 4:
        print(f"L{counter} = 1;")
        counter += 1
    counter = 1        
    while counter <= 4:
        print(f"if(C{counter} == 0) res = {key};")
        key += 1
        counter += 1
    print()        