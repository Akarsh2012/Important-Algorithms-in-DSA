/*
Approach:
- This solution is based on a **prefix-suffix** strategy.
- We traverse the array twice, once from the front (prefix) and once from the back (suffix).
- At each index, we calculate the product of elements from the beginning (prefix) and the end (suffix).
- We maintain the maximum product encountered during these traversals.
- If either prefix or suffix product becomes zero (due to a zero in the array), we reset it to 1 to start fresh since a subarray starting after that zero might have a higher product.
- The idea behind using both prefix and suffix is to avoid missing a possible maximum product subarray that may be disrupted by zeros in the middle.

Time Complexity: O(n)
- We iterate through the array twice (once for prefix and once for suffix), so the time complexity is linear with respect to the number of elements in the array.

Space Complexity: O(1)
- We are only using a constant amount of extra space (for variables `prefix`, `suffix`, and `ans`), so the space complexity is constant.
*/
/*
Approach:
- यह समाधान **prefix-suffix** रणनीति पर आधारित है।
- हम एरे को दो बार ट्रैवर्स करते हैं, एक बार आगे से (prefix) और एक बार पीछे से (suffix)।
- प्रत्येक इंडेक्स पर, हम शुरुआत से (prefix) और अंत से (suffix) एलिमेंट्स का प्रोडक्ट निकालते हैं।
- हम इन ट्रैवर्सल के दौरान मिले अधिकतम प्रोडक्ट को स्टोर करते हैं।
- यदि prefix या suffix का प्रोडक्ट शून्य हो जाता है (क्योंकि एरे में शून्य हो सकता है), तो इसे 1 से रीसेट कर देते हैं ताकि शून्य के बाद शुरू होने वाले सबएरे का प्रोडक्ट ज़्यादा हो सकता है।
- Prefix और suffix दोनों का उपयोग इसलिए किया जाता है ताकि एरे के बीच में आए शून्य के कारण किसी संभावित अधिकतम प्रोडक्ट सबएरे को मिस न किया जाए।
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        // Initialize prefix and suffix product as 1
        int prefix = 1;
        int suffix = 1;

        // Initialize the result with the minimum possible integer value
        int ans = INT_MIN;

        // Loop through the array from start to end for prefix and end to start for suffix
        for (int i = 0; i < n; i++)
        {
            // Reset prefix or suffix to 1 if they become zero
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            // Multiply prefix by current element and suffix by the corresponding element from the end
            prefix *= nums[i];
            suffix *= nums[n - 1 - i];

            // Update the answer with the maximum of the current prefix or suffix product
            ans = max(ans, max(prefix, suffix));
        }

        // Return the maximum product found
        return ans;
    }
};
