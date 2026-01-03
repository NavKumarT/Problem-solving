// Last updated: 1/3/2026, 12:25:00 PM
/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    nums.forEach((num) => {
        init = fn(init, num);
    })
    return init;
};