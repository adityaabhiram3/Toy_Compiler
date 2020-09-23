import re
import sys
global max_cnt
global reg
global rn 
global br_fl

reg = {}
max_cnt=13
rn=0
num_allowed=[0,1,2,3,4,5,6,7,8,9,10,11,12,13]

def next_reg():
    global reg
    global rn
    global max_cnt
    global num_allowed
    allowed = set()
    list_of_nums=[]
    signal=0
    for x in reg: 
    	value=reg[x]
    	splitz=re.split("R",value)#R/0
    	list_of_nums.append(int(splitz[1]))
    allowed = set(num_allowed)-set(list_of_nums)
    if(allowed):
        signal=1
        i = list(allowed)[0]

    if(signal==1):
    	return i
    else:
    	max_cnt+=1
    	rn+=1
    	return rn


def goto():
    global br_fl
    global value
    if(br_fl == "<"): 
        print("BGT ", value)
    elif(br_fl == ">"):
        print("BLT ", value)
    elif(br_fl == ">="):
        print("BLTE ", value)
    elif(br_fl == "<="):
        print("BGTE ", value)
    elif(br_fl == "=="):
        print("BEQ ", value)    
    elif(br_fl == "!="):
        print("BNE ", value)
    br_fl = ""

def non_temp():
    global rn
    global result_var
    global reg_name
    global value
    global var_name2
    reg_name = "R"+str(rn) 

    if(result_var not in reg): 
        reg[result_var] = reg_name 
        print("LDR ", reg_name, ",=", result_var) 

    rn = next_reg() 

    reg_name = "R"+str(rn)  

    if(value_type == None):  
        print("MOV ", reg_name, ",#", value) 

    else: 

        reg_name = "R"+str(rn)
        value = reg[value] 
        print("MOV ", reg_name, ",", value) 
        rn = next_reg()

    reg_name = "R"+str(rn)

    var_name2=reg[result_var] 
    print("STR ", reg_name, ",[", var_name2, "]") 
    rn = next_reg()

def temp():
    global rn
    global reg_name
    global result_var
    global value
    reg_name = "R"+str(rn)

    if(value_type == None):  
        print("MOV ", reg_name, ",#", value)

    else: 
        value = reg[value]
        print("MOV ", reg_name, ",", value)

    reg[result_var] = reg_name 
    rn = next_reg()



if len(sys.argv) == 2:
    input_file = str(sys.argv[1])

list_of_lines = []
br_fl = ""
f = open(input_file, "r")

for ln in f:
    ln = ln.strip()
    list_of_lines.append(ln)
f.close()

for ln in list_of_lines:
    split_line = ln.split() 
    split_len = len(split_line) 
    if(split_len == 3): 
        result_var = split_line[0]
        oper = split_line[1] 
        value = split_line[2] 

        type_v = re.search("^T[0-9]+", result_var)

        value_type = re.search("^[a-zA-Z]", value) 

        if(oper == "goto"): 
            goto()
        elif(type_v == None):  
            non_temp()
        else:  
            temp()
            

    elif(split_len == 5):  
        result_var = split_line[0]
        operand_1 = split_line[2] 
        oper = split_line[3] 
        operand_2 = split_line[4] 
        var = re.search("^[a-zA-Z]", operand_1)
        checker = re.search("^T[0-9]+", result_var)

        if(var == None):  
            register_nm = "R"+str(rn) 
            rn = next_reg()
            print("MOV ", register_nm, ", #", operand_1)

        else:  
            register_nm = reg[operand_1]


        var = re.search("^[a-zA-Z]", operand_2)
        if(var == None):  
            register_nm_s = "R"+str(rn)
            rn = next_reg()
            print("MOV ", register_nm_s, ",#", operand_2)
        else:  
            register_nm_s = reg[operand_2]

        if(oper == '<'): 
            br_fl = "<" 
            print("CMP ", register_nm, ", ", register_nm_s)
            reg_name = "R"+str(rn)
            reg[result_var] = reg_name
            rn = next_reg()
            
        elif(oper == '<='):
            br_fl = "<="
            print("CMP ", register_nm, ", ", register_nm_s)
            reg_name = "R"+str(rn)
            reg[result_var] = reg_name
            rn = next_reg()
            
        elif(oper == '>='):
            br_fl = ">="
            print("CMP ", register_nm, ", ", register_nm_s)
            reg_name = "R"+str(rn)
            reg[result_var] = reg_name
            rn += 1
            
        elif(oper == '>'):
            br_fl = ">"
            print("CMP ", register_nm, ", ", register_nm_s)
            reg_name = "R"+str(rn)
            reg[result_var] = reg_name
            rn = next_reg()
        elif(oper == '=='):
            br_fl = "=="
            print("CMP ", register_nm, ", ", register_nm_s)
            reg_name = "R"+str(rn)
            reg[result_var] = reg_name
            rn = next_reg()
        elif(oper == '!='):
            br_fl = "!="
            print("CMP ", register_nm, ", ", register_nm_s)
            reg_name = "R"+str(rn)
            reg[result_var] = reg_name
            rn = next_reg()

    
        elif(oper == "+"):
            rn+=1
            reg_name = "R"+str(rn)
            if(checker==None): 
                    result_var3=reg[result_var] 
                    print("MOV ", reg_name, ",", result_var3)

            else: 
                    if(result_var not in reg): 
                            reg_name = "R"+str(rn)
                            reg[result_var] = reg_name
                            rn = next_reg()
                            newvar=reg_name
                            print("MOV ", reg_name, ",#0")

                    else:
                            print("MOV ", reg_name, ",", result_var)
            reg[result_var] = reg_name
            
            rn = next_reg()
            print("ADD ", reg_name, ",", register_nm, ',', register_nm_s)
            
        elif(oper == "-"): 
            rn+=1
            reg_name = "R"+str(rn)
            if(checker==None):
                    result_var3=reg[result_var]
                    print("MOV ", reg_name, ",", result_var3)
            else:
                    if(result_var not in reg):
                            reg_name = "R"+str(rn)
                            reg[result_var] = reg_name
                            rn = next_reg()
                            newvar=reg_name
                            print("MOV ", reg_name, ",#0")
                    else:
                            print("MOV ", reg_name, ",", result_var)
            reg[result_var] = reg_name
            
            rn = next_reg()
            print("SUB ", reg_name, ",", register_nm, ',', register_nm_s)
            

        elif(oper == "*"):
            reg_name = "R"+str(rn)
            print("MOV ", reg_name, ",", result_var)
            reg[result_var] = reg_name
            
            rn = next_reg()
            print("MUL ", reg_name, ",", register_nm, ',', register_nm_s)
            
        
    elif(split_len == 2): 
        result_var = split_line[0]
        value = split_line[1]
        if(result_var == "goto"):
            print("B ", value)
        else:
            print(ln)
            

