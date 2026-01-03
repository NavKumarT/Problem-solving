// Last updated: 1/3/2026, 12:25:05 PM
/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(millis);
        }, millis);
    });
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */