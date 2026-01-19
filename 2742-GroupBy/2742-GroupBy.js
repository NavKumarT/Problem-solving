// Last updated: 1/19/2026, 12:38:16 PM
/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    let map = {};
    this.forEach((el) => {
        let funcValue = fn(el); // string 
        if(map[funcValue]){
            map[funcValue].push(el);
        } else {
            map[funcValue] = [el];
        }
    })
    return map;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */