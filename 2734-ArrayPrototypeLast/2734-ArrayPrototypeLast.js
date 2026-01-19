// Last updated: 1/19/2026, 12:38:17 PM
/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    return this.length > 0 ? this[this.length-1] : -1;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */