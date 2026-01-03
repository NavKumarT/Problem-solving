// Last updated: 1/3/2026, 12:25:02 PM
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let filteredArr = [];
    for(let i = 0; i < arr.length; i++){
        if(fn(arr[i], i))
            filteredArr.push(arr[i]);
    }
    return filteredArr;
};