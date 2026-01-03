// Last updated: 1/3/2026, 12:24:59 PM
/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let count = init;
    let start = init;

    const increment = () => {
        count++;
        return count;
    }
    const decrement = () => {
        count--;
        return count;
    }
    const reset = () => {
        count = start;
        return count;
    }
    return {increment, decrement, reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */