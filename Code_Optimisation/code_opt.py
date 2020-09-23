import re
import sys

def remove_sub(noLines) : #elimination of common subexpressions
	exp = expr(noLines)
	lines = len(noLines)#number of lines
	newLines = noLines
	for i in range(lines) :
		split_tok = noLines[i].split()
		if len(split_tok) == 5 :
			rhs = split_tok[2] + " " + split_tok[3] + " " + split_tok[4]
			if rhs in exp and exp[rhs] != split_tok[0]: 
				newLines[i] = split_tok[0] + " " + split_tok[1] + " " + exp[rhs] #temporary assignemnt 
	return newLines


def expr(noLines) :
	exp = {} #actual rhs:lhs 
	var = {} # check and eliminate the repeated rhs. 
	for line in noLines :
		split_tok = line.split()
		if len(split_tok) == 5 :#evaluation expression
			if split_tok[0] in var and var[split_tok[0]] in exp : #index on LHS , value for RHS
				del exp[var[split_tok[0]]] #so repeat in sub expression, you replace by temporary already containing subexpression
			rhs = split_tok[2] + " " + split_tok[3] + " " + split_tok[4] #get rhs expression
			if rhs not in exp : 
				exp[rhs] = split_tok[0] #indexing based on rhs, in exp to avoid repetition of rhs
				if is_var(split_tok[2]) : #if op1 is a var
					var[split_tok[2]] = rhs #lhs : rhs
				if is_var(split_tok[4]) : 
					var[split_tok[4]] = rhs
	return exp

def fold(noLines) :#constant folding

	newLines = []
	for line in noLines :
		newLines.append(evaluate_exp(line))
	return newLines


def evaluate_exp(line) :
	split_tok = line.split()
	if len(split_tok) != 5 :
		return line
	if split_tok[1] != "=" or split_tok[3] not in {"+", "-", "*", "/", "*", "&", "|", "^", "=  =", "> =", "< =", "! =", ">", "<"}:
		return line
	if split_tok[2].isdigit() and split_tok[4].isdigit() :
		result = eval(str(split_tok[2] + split_tok[3] + split_tok[4]))
		return " ".join([split_tok[0], split_tok[1], str(result)])

	return line
	
is_var = lambda s : bool(re.match(r"^[A-Za-z][A-Za-z0-9_]*$", s)) 				

if __name__ == "__main__" :

	file = str(sys.argv[1])
	noLines = []
	f = open(file, "r")
	flag=0
	
	for line in f :
		flag = 1
		if(flag):
			if(line=="\n"):
				continue
			noLines.append(line)
		else:
			continue
	f.close()
	part_1 = remove_sub(noLines)
	part_2 = fold(part_1)
	

	for line in part_2 :
		print(line.strip())
	

