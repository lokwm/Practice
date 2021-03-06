### 题目
有个马戏团正在设计叠罗汉的表演节目，一个人要站在另一人的肩膀上。出于实际和美观的考虑，在上面的人要比下面的人矮一点且轻一点。已知马戏团每个人的身高和体重，请编写代码计算叠罗汉最多能叠几个人。

示例：

输入：height = [65,70,56,75,60,68] weight = [100,150,90,190,95,110]
输出：6
解释：从上往下数，叠罗汉最多能叠 6 层：(56,90), (60,95), (65,100), (68,110), (70,150), (75,190)


### 思路
先按照身高排序(希尔排序，时间93.99，内存91.89，冒泡时间过长)，然后按求最大子序列长度方法即可

### 代码
~~~ c++
class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        int right=height.size();
        for (int increase = right / 2; increase > 0; increase /= 2) {
        for (int i = increase; i < right; i++) {
            int tmp = height[i];
            int tmpwei = weight[i];
            int j = 0;
            for (j = i; j >= increase; j -= increase) {
                if (tmp < height[j - increase]||(tmp==height[j-increase]&&tmpwei>weight[j-increase])) {       //希尔排序
                    height[j] = height[j - increase];
                    weight[j] = weight[j - increase];
                }
                else
                    break;
            }
            height[j] = tmp;
            weight[j] = tmpwei;
        }
    }

        vector<int> d(right+1); 
        int len=0;
        d[++len]=weight[0];
        for(int i=0;i<right;i++){
            if(weight[i]>d[len])d[++len]=weight[i];
            else{
                int left=1,r=len;
                while(left<=r){
                    int mid=(left+r)>>1;
                    if(d[mid]<weight[i]){
                        left=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
                d[left]=weight[i];
            }
        }
        return len;
    }
};
~~~
