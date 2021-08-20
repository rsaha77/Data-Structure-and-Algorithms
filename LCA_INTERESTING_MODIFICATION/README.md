Example of this problem appeared here: https://www.codechef.com/problems/TALCA/

Solution:1 (Implemented)
https://discuss.codechef.com/t/talca-editorial/6527


Solution:2 (Simpler Solution)
https://stackoverflow.com/questions/25371865/find-multiple-lcas-in-unrooted-tree?rq=1

Explanation;
Let LCA(u, v, w) be the LCA of v and w with respect to root u. To compute LCA(u, v, w), we can compute, for any fixed r,

LCA(r, u, v)
LCA(r, u, w)
LCA(r, v, w)

and take the "odd man out", i.e., if two are equal and the third is different, then take the third, else they're all equal, so take that node.
