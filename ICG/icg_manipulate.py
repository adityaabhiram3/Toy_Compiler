import re
icg_reference = open("out.txt","r")
lines = icg_reference.readlines()
modified_lines = []
instant_val = ''
for i in range(len(lines)):
    if(':' in lines[i]):
        lines[i] = lines[i].split(':')[0]+'\n'
for i in lines:
	for j in i:
		if(j == '='):
			instant_val += ' = '
		else:
			instant_val += j
	modified_lines.append(instant_val)
	instant_val = ''

        

        
i=0
for i in range(len(modified_lines)):
	if(len(modified_lines[i])==3 or len(modified_lines[i])==4):
		sped = modified_lines[i].split('\n')
		sped[0] += ' :'
		modified_lines[i] = sped[0] + '\n'
for i in range(len(modified_lines)):
	if('not' in modified_lines[i]):
		tek1 = modified_lines[i-1].split()
		tek2 = modified_lines[i+1].split()
		flex = 'ifno'+tek1[0]+' '+tek2[2]+' '+tek2[3]+'\n'
		modified_lines[i+1] = flex
index_delete = []
for i in range(len(modified_lines)):
	if('not' not in modified_lines[i]):
		index_delete.append(modified_lines[i])
modified_lines = index_delete
x = dict()
var_counter=0
i=0
while(not re.search("^L[0-9]+", modified_lines[i])):
	print(modified_lines[i])
	i+=1
while(i<len(modified_lines)):
	toks=modified_lines[i].split()
	l1=toks[0]

	if(re.search("^L[0-9]+", l1)):
		#find out whether L0...L10 so assign first, iterate through full program, searching for the other Lnums
		#What could be modified in the previous program: iterate further through the program, to find other Lnums
		reg="L"+str(var_counter)
		#iterate through and find all L0's, sequentially
		ll=[]

		for j in range(i,len(modified_lines)):
			if(len(modified_lines[j])==5 or len(modified_lines[j])==6):
				tks= modified_lines[j].split()
				lhs=tks[0]
			if(lhs==reg):
				
				#split on tokens, get the first token
				#directly enter string
				if(re.search("^L[0-9]+", modified_lines[j])):
					j=i+1
					continue
				else:

					ll.append(modified_lines[j])
		x[reg]=ll
		var_counter+=1
	#flag the marked / added L's
	i+=1

x['L10'] = ['SWI 0x11']
for i in x.keys():
	if i == 'L11':
		continue
	print(i + ' :\n')
	for j in x[i]:
		print(j)



















