
inp = input("How many colors are you paning to implement?\n>> ")

if (not inp.isdigit()):
	print("Please input a number")
	exit(0)
ln = int(inp)

inp = input("What is the index of the array?\n>> ")

if (not inp.isdigit()):
	print("Please input a number")
	exit(0)

index = int(inp)

colors = []

for i in range(ln):
	colors.append(input(f"Color #{i}\n>> "))
	if not colors[i].startswith('0x'):
		if colors[i].startswith('0X'):
			colors[i] = colors[i][2:]
		colors[i] = f'0x{colors[i]}'

outC = ', '.join(colors)

out = f"\tarray[{index}] =\n\t\t(t_pallete){'{'}{ln}, 0, {'{'}{outC}{'}'}{'}'};"
print (out)