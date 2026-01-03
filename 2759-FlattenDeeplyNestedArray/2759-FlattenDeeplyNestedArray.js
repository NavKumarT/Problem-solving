// Last updated: 1/3/2026, 2:07:26 PM
var flat = function (arr, n) {
    if (n === 0) return arr;

    const result = [];

    for (const el of arr) {
        if (Array.isArray(el)) {
            result.push(...flat(el, n - 1));
        } else {
            result.push(el);
        }
    }

    return result;
};
