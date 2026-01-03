// Last updated: 1/3/2026, 7:07:24 PM
/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let a = 0, b = 1;
    while(true){
        let temp = a;
        a = b;
        b = b+temp;
        yield temp;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */