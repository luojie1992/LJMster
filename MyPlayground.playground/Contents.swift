import UIKit

var str = "Hello, playground"
str.append("luojie")
str.insert("i",at: str.endIndex)
var dict1 = [1:"A",2:"B",3:"C",4:"D",5:"E"];
var a =  dict1.keys ;
var testString:String = "123455"
var testDic = [String:String]()

testDic["123"] = "456"
print(testString)
for c in testString{
    let catString = String(c)
    print(catString)
    
}

var arrAll = [7,1,4,3,6]
var  maxprofit = 0
var  minprice  = 10
for a in arrAll {
    if a < minprice {
        minprice = a
    }else {
        maxprofit = max(a - minprice,maxprofit)
    }
    print(maxprofit)
}

func maxSubArray(_nums:[Int])->Int{
    var sum = 0
    var max:Int = 0
    for i in _nums.count {
        sum = 0
        for j in i..<_nums.count {
            sum += _nums[j]
            if sum > max {
                max = sum
            }
        }
    }
    return max
}


var a11 = 5
while a11 < 10 {
    print(a11) ;
    a11 += 1 ;
}

for (index, value) in ["1","2","3"].enumerated(){
    print(value)
}

class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        if s.count == 0 {
            return 0 ;
        }
        var dataDic = [String:String]()
        for c in s {
            let realString = String(c)
            dataDic.updateValue(realString,forKey:realString)
            
        }
        
        return dataDic.count
        
    }
}

let solve  = Solution()
let result = solve.lengthOfLongestSubstring("abcabcbb")


class Solution1 {
    func checkInclusion(_ s1: String, _ s2: String) -> Bool {
        guard s1.count <= s2.count else {
            return false
        }
        
        func allZero(_ counts: [Int]) -> Bool {
            for i in 0 ..< 26 {
                if counts[i] != 0 {
                    return false
                }
            }
            return true
        }
        let a1 = "G"
        for scalar in a1.unicodeScalars {
            print("\(scalar.value)")
        }
        let chars1 = Array(s1.unicodeScalars)
        let chars2 = Array(s2.unicodeScalars)
        let len1 = chars1.count
        let len2 = chars2.count
        var counts = [Int](repeatElement(0, count: 26))
        for i in 0 ..< len1 {
            counts[Int(chars1[i].value - 97)] += 1
            counts[Int(chars2[i].value - 97)] -= 1
        }
        if allZero(counts) { return true }
        
        for i in len1 ..< len2 {
            counts[Int(chars2[i].value - 97)] -= 1
            counts[Int(chars2[i - len1].value - 97)] += 1
            if allZero(counts) { return true }
        }
        
        return false
    }
}

let solve1 = Solution1()
let result1 = solve1.checkInclusion("kl","asdfasdfadfkl")
print(result1)
