class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:


    def serialize(self, root):
        if root is None:
            return "{}"

        queue = [root]
        index = 0
        while index < len(queue):
            if queue[index] is not None:
                queue.append(queue[index].left)
                queue.append(queue[index].right)
            index += 1

        while queue[-1] is None:
            queue.pop()

        return '{%s}' % ','.join([str(node.val) if node is not None else '#'
                                  for node in queue])


    def deserialize(self, data):
        data = data.strip('\n')

        if data == '{}':
            return None

        vals = data[1:-1].split(',')
            
        root = TreeNode(int(vals[0]))
        queue = [root]
        isLeftChild = True
        index = 0

        for val in vals[1:]:
            if val is not '#':
                node = TreeNode(int(val))
                if isLeftChild:
                    queue[index].left = node
                else:
                    queue[index].right = node
                queue.append(node)

            if not isLeftChild:
                index += 1
            isLeftChild = not isLeftChild

        return root
if __name__ == '__main__':
	'''
	An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:

	  3
	 / \
	9  20
	  /  \
	 15   7
	Our data serialization use bfs traversal. This is just for when you got wrong answer and want to debug the input.

	You can use other method to do serializaiton and deserialization.
	'''
	root = TreeNode(3)
	root.left,root.right = TreeNode(9),TreeNode(20)
	node = root.right
	node.left,node.right = TreeNode(15), TreeNode(7)
	sol = Solution()
	res = sol.serialize(root)
	print res

