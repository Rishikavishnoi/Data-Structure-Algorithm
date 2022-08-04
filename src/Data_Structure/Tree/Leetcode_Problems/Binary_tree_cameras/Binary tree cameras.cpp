/* Approach :
0 -> Installing a camera is required for this node (0 Cam monitor it).
1 -> Camera is not needed for this node (1 Cam monitor it).
2 -> This already has a camera installed (Cam fix here which monitor parent node and child nodes).
*/

class Solution
{
public:
    int minCameraCover(TreeNode* root)
    {
        int cam = 0;
        int minCam = cover(root, cam);

        if(minCam==0) //need to install a camera here
            cam++;

        return cam;
    }

    int cover(TreeNode* root, int &cam)
    {
        if(root==NULL) return 1;

        //Going to the leaf nodes
        int left = cover(root->left, cam);
        int right = cover(root->right, cam);

        //While returning to the top we check which node needs camera
        if(left==0 || right==0)
        {
            //installing camera here
            cam++;
            return 2;
        }

        else if(left==2 || right==2)
            // does not need camera
            return 1;

        //for (left==1 || right==1) condition
        // children does not need a camera but parents have
        return 0;
    }

};
