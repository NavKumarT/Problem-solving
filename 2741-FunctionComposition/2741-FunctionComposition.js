// Last updated: 1/3/2026, 12:25:04 PM
/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {
        // start from the end and execute all functions 
        let calcValue = x;
        for(let i = functions.length-1; i >= 0; i--){
            calcValue = functions[i](calcValue);
        }   
        return calcValue;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */