const scale = 3
const paddingContent = -Infinity
const horizontalData = 
    [1, 2,
     3, 4, 2]

const data = horizontalData.reduce((acc, next) =>
    acc.concat(new Array(scale).fill(next))
, [])

const { length } = data

const padding = length % 4

const dataWithPadding = data.concat(new Array(padding).fill(paddingContent))
// console.log(dataWithPadding)

const resizableArray = [
    [1, 2, 3],
    [4, 5, 6]
]

const resized = resizableArray.reduce((arr, nextArray) => {
    const horizontal = nextArray.reduce((acc, next) => {
        acc.push(new Array(scale).fill(next))
        return acc
    }
    , [])
    return arr.concat(...new Array(scale).fill(horizontal))
}, [])

console.log(resized)