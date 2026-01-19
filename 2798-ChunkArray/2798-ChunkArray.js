// Last updated: 1/19/2026, 12:38:07 PM
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let curr = 0, temp = [], currArr = [];
    for(let el of arr){
        if(curr === size){
            temp.push(currArr);
            curr = 1;
            currArr = [el];
        } else {
            curr++;
            currArr.push(el);
        }
    }
    if(currArr.length <= size && currArr.length !== 0){
        temp.push(currArr);
    }
    return temp;
};
