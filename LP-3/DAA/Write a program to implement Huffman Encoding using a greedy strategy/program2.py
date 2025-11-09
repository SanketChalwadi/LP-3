# A Huffman Tree Node
class Node:
    def __init__(self, freq, symbol, left=None, right=None):
        # frequency of symbol
        self.freq = freq
        # symbol name (character)
        self.symbol = symbol
        # node left of current node
        self.left = left
        # node right of current node
        self.right = right
        # tree direction (0/1)
        self.huff = ''

# Utility function to print Huffman codes
def printNodes(node, val=''):
    # huffman code for current node
    newVal = val + str(node.huff)

    # if node has a left child
    if node.left:
        printNodes(node.left, newVal)
    # if node has a right child
    if node.right:
        printNodes(node.right, newVal)

    # if node is a leaf node (symbol)
    if not node.left and not node.right:
        print(f"{node.symbol} -> {newVal}")

# characters for huffman tree
chars = ['a', 'b', 'c', 'd', 'e', 'f']

# frequency of characters
freq = [5, 9, 12, 13, 16, 45]

# list containing unused nodes
nodes = []

# converting characters and frequencies into huffman tree nodes
for x in range(len(chars)):
    nodes.append(Node(freq[x], chars[x]))

while len(nodes) > 1:
    # sort all the nodes in ascending order based on their frequency
    nodes = sorted(nodes, key=lambda x: x.freq)

    # pick 2 smallest nodes
    left = nodes[0]
    right = nodes[1]

    # assign directional value to these nodes
    left.huff = 0
    right.huff = 1

    # combine the 2 smallest nodes to create new node as their parent
    newNode = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)

    # remove the 2 nodes and add their parent node
    nodes.remove(left)
    nodes.remove(right)
    nodes.append(newNode)

# Huffman Tree is ready!
printNodes(nodes[0])
