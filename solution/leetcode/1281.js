// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    s = n.toString().split('');
    product = s.reduce((sum, cur) => sum*parseInt(cur), 1);
    sum = s.reduce((sum, cur) => sum + parseInt(cur), 0);
    return product - sum;
};
