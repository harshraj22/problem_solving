// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
// Copied implementation just to get familiar with js
var kidsWithCandies = function(candies, extraCandies) {
    let maxCandies = Math.max(...candies);
    return candies.map(candy => candy+extraCandies >= maxCandies);
};
