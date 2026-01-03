// Last updated: 1/3/2026, 12:25:07 PM
/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let map = {};
    return function(...args) {
        const [cacheHit, value] = checkCache(map, args);
        if(cacheHit){
            return value;
        } else {
            const calculatedValue = fn(...args);
            map[args] = calculatedValue;
            return calculatedValue;
        }
    }
}

function checkCache(map, args){
    // const keys = Object.keys(map);
    if(map[args] !== undefined)
        return [true, map[args]];
    return [false, -1];
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */