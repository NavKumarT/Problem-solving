// Last updated: 1/3/2026, 12:25:01 PM
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let mappedArr = [];
    for(let i = 0; i < arr.length; i++){
        mappedArr.push(fn(arr[i], i));
    } 
    return mappedArr;
};