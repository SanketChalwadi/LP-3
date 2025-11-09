# Huffman Coding Program (for any given input)

class Node:
    def __init__(self, freq, symbol, left=None, right=None):
        self.freq = freq            # frequency of symbol
        self.symbol = symbol        # symbol name (character)
        self.left = left            # left child
        self.right = right          # right child
        self.huff = ''              # tree direction (0/1)


# Utility function to print Huffman codes
def printNodes(node, val=''):
    newVal = val + str(node.huff)

    if node.left:
        printNodes(node.left, newVal)
    if node.right:
        printNodes(node.right, newVal)

    if not node.left and not node.right:
        print(f"{node.symbol} -> {newVal}")


# ---------- MAIN PROGRAM ----------
# Take input from user
n = int(input("Enter number of characters: "))

chars = []
freq = []

for i in range(n):
    ch = input(f"Enter character {i+1}: ")
    f = int(input(f"Enter frequency of '{ch}': "))
    chars.append(ch)
    freq.append(f)

# Create list of nodes
nodes = [Node(freq[i], chars[i]) for i in range(len(chars))]

# Construct Huffman Tree
while len(nodes) > 1:
    # sort nodes by frequency
    nodes = sorted(nodes, key=lambda x: x.freq)

    # pick two smallest
    left = nodes[0]
    right = nodes[1]

    # assign 0 and 1
    left.huff = 0
    right.huff = 1

    # create new combined node
    newNode = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)

    # update list
    nodes.remove(left)
    nodes.remove(right)
    nodes.append(newNode)

# Print Huffman Codes
print("\nHuffman Codes for given input:")
printNodes(nodes[0])
