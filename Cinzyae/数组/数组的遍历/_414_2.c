/*
给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。



示例 1：

输入：[3, 2, 1]
输出：1
解释：第三大的数是 1 。

示例 2：

输入：[1, 2]
输出：2
解释：第三大的数不存在, 所以返回最大的数 2 。

示例 3：

输入：[2, 2, 3, 1]
输出：1
解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。



提示：

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1



进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/third-maximum-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int thirdMax(int *nums, int numsSize)
{
    int Maxnums[3] = {-2 ^ 31, -2 ^ 31, -2 ^ 31};
    int flag = 0;
    int Min = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == -2 ^ 31)
        {
            Min = 1;
        }

        if (nums[i] == Maxnums[0] || nums[i] == Maxnums[1] || nums[i] == Maxnums[2])
        {
            continue;
        }

        if (nums[i] > Maxnums[0])
        {
            flag++;
            Maxnums[2] = Maxnums[1];
            Maxnums[1] = Maxnums[0];
            Maxnums[0] = nums[i];
        }
        else if (nums[i] > Maxnums[1])
        {
            flag++;
            Maxnums[2] = Maxnums[1];
            Maxnums[1] = nums[i];
        }
        else if (nums[i] > Maxnums[2])
        {
            flag++;
            Maxnums[2] = nums[i];
        }
    }
    if (Min == 1)
    {
        flag++;
    }

    if (flag < 3)
    {
        return Maxnums[0];
    }

    return Maxnums[2];
}
