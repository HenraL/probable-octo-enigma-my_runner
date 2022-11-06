import random, sys

width = 1920 * 100
heigth = 1080

list_of_elements = ["nothing", "ice_wall", "ice_snow_block", "ice_cube", "only_snow"]
list_of_enemies = ["eggman","rocket","spike"]
list_of_all = []
dict_of_all =  {}
if (len(sys.argv) > 1):
    level_name = sys.argv[1]
    count = 0
    for i in range(len(list_of_elements)):
        dict_of_all[list_of_elements[i]] = count
        list_of_all.append(list_of_elements[i])
        count+=1

    for i in range(len(list_of_enemies)):
        dict_of_all[list_of_enemies[i]] = count
        list_of_all.append(list_of_enemies[i])
        count+=1
    count += -1
    f = open(f"{level_name}.runner", "w")
    f.close()

    for i in range(heigth):
        print(i)
        for b in range(width):
            character = random.randint(0,count-1)
            f = open(f"{level_name}.runner", "a")
            f.write(f"{dict_of_all[list_of_all[int(character)]]}|")
            f.close()
        f = open(f"{level_name}.runner", "a")
        f.write("\n")
        f.close()
