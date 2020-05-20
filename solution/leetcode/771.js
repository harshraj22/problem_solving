// https://leetcode.com/problems/jewels-and-stones/

/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    J = Array.from(J); S = Array.from(S);
    return J.reduce((prev, val) => prev + S.filter(x => x === val).length, 0)
};
