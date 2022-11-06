f = open("level1.runner","r")
content = f.read()
f.close()

print(f"file_content = {content}")

def treat1(file_cotnent):
    #beg_of_sprite = 0
    end_of_spriterite = 0
    in_elem_of_sprite = 0
    sprite_count = 0
    list_index = ["id","pos_y","clock","name","type"]
    list_index_track = 0
    final_list = []
    temp_dict = {}
    temp = ""
    for i in content:
        print(f"i = {i}")
        if (i == "|"):
            print("i = |")
            end_of_sprite = 1
            sprite_count +=1
            list_index_track = 0
            final_list.append(temp_dict)
            temp_dict = {}
        if ( i != "|" and i == ","):
            print("i != | and i == ,") 
            temp_dict[list_index[list_index_track]] = temp
            temp = ""
            in_elem_of_sprite = 1
            list_index_track +=1
        if ( in_elem_of_sprite == 1 and i != "|" and i != ","):
            print("in_elem_of_sprite == 1 and i != | and i != ,")
            temp += i
    return final_list

def treat2(file_content):
    list_index = ["id","pos_y","clock","name","type"]
    final_list = []
    temp_dict = {}
    temp = ""
    index_track = 0
    for i in content:
        #print(f"i = {i}")
        if (i == "|"):
            #print("i == |")
            final_list.append(temp_dict)
            temp_dict={}
            index_track = 0
        if (i != "|" and i==","):
            #print("i != | and i == ,")
            temp_dict[list_index[index_track]] = temp
            temp = ""
            index_track +=1
        if (i != "|" and i!=","):
            temp += i
            print(f"temp = {temp}")
    return final_list
            


final_list = treat2(content)

print(f"file_content = {content}")
print(final_list)
