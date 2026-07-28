class Solution {
public:

    static double median(vector<int> &arr , int num1 , int num2){
        int sum = num1 + num2;

        if (sum % 2 ==1){
            return arr[sum/2];
        }
        else{
            return ((arr[sum/2 -1 ] + arr[sum / 2])/2.00);
        }
    }
    static void merge(vector<int> &arr , int left , int right , int mid){

        vector <int> temp_arr;
        int i = left , j = mid + 1;

        while(i <= mid && j<= right){
            if (arr[i] <= arr[j]){
                temp_arr.push_back(arr[i++]);
            }
            else{
                temp_arr.push_back(arr[j++]);
            }
        }

        while(i <= mid){
            temp_arr.push_back(arr[i++]);
        }

        while(j <= right ){
            temp_arr.push_back(arr[j++]);
        }

        for(int k = left ; k <= right ; k++){

            arr[k] = temp_arr[k - left];
        }
    }

    static void mergesort(vector<int> &arr , int left , int right){
        if(left >= right){
            return;
        }

        int mid = (left + right)/2;

        mergesort(arr, left , mid);
        mergesort(arr, mid+1,right);
        merge(arr , left , right , mid);
    }
        
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        vector<int> arr;
        arr.reserve(size1+size2);

        for(int val : nums1 ){
            arr.push_back(val);
        }

        for(int val : nums2 ){
            arr.push_back(val);
        }

        if(size1 > 0 && size2 > 0){
            merge(arr , 0 , size1+size2-1 , size1-1);
        }

        return median(arr , size1 , size2);
    }

};
