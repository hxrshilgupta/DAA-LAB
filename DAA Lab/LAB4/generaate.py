# Generating the sequence and writing it to a file
with open("inAsce.dat", "w") as file:
    file.write("10000\n")
    for i in range(1, 10001):
        file.write(str(i) + " ")