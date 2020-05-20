////
//  DZ_Algorithm.swift
//  LJMster
//
//  Created by jiejie on 2020/3/6.
//  Copyright © 2020 jiejie. All rights reserved.
//

import UIKit

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

class DZ_Algorithm: NSObject {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        if l1 == nil, l2 == nil {
            return nil
        }
        var l1 = l1, l2 = l2
        var carry = 0
        let link = ListNode(0)
        var nextNode = link
        while l1 != nil || l2 != nil {
            let sum = (l1?.val ?? 0) + (l2?.val ?? 0) + carry
            carry = sum/10
            nextNode.val = sum%10
            l1 = l1?.next
            l2 = l2?.next
            if l1 == nil, l2 == nil {
                if carry > 0 {
                    let node = ListNode(1)
                    nextNode.next = node
                    break
                }
            }else {
                let node = ListNode(0)
                nextNode.next = node
                nextNode = node
            }
        }
        return link
    }
    
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dict = [Int: Int]()
        for (index, value) in nums.enumerated() {
            dict[value] = index
        }
        for (currentIndex, value) in nums.enumerated() {
            if let index = dict[target - value], index != currentIndex {
                return [currentIndex, index]
            }
        }
        return []
    }
    // 最长子序列
    func lengthOfLongestSubstring(_ s: String) -> Int {
        
        var lastDuplicatePosition = -1
        var index = 0
        var maxLength = 0
        var dict = [Character: Int]()
        for c in s {
            if let lastIndex = dict[c], lastIndex > lastDuplicatePosition {
                lastDuplicatePosition = lastIndex
            }
            maxLength = max(maxLength, index - lastDuplicatePosition)
            dict[c] = index
            index += 1
        }
        return maxLength
    }
    
    func test(a:String,b:String) -> Int {
        let a1 = DZ_Algorithm() ;
        _ =  a1.addTwoNumbers(ListNode.init(1), ListNode.init(2)) ;
        return 2 ;
    }

    // 反转链表
    func reverseList(_ head: ListNode?) -> ListNode? {
        if head == nil || head?.next == nil {
            return head
        }
        
        var newHead: ListNode? = ListNode.init(0).next
        var p = head
        while p != nil {
            let tmp = p?.next
            p?.next = newHead
            newHead = p
            p = tmp
        }
        return newHead
    }

    // 合并两个有序数组
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var i = m - 1, j = n - 1
        while i >= 0 || j >= 0 {
            if j < 0 || (i >= 0 && nums1[i] > nums2[j]) {
                nums1[i + j + 1] = nums1[i]
                i -= 1
            } else {
                nums1[i + j + 1] = nums2[j]
                j -= 1
            }
        }
    }
    
    func merge1(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        //双指针 从后往前
        var p1 = m-1
        var p2 = n-1
        var p = m+n-1
        while p1>=0 && p2>=0 {
            if  nums1[p1] <= nums2[p2]{
                nums1[p] = nums2[p2]
                p2 -= 1
                p -= 1
            }else{
                nums1[p] = nums1[p1]
                p1 -= 1
                p -= 1
                
            }
        }
        while p2 >= 0 {
            nums1[p] = nums2[p2]
            p -= 1
            p2 -= 1
        }
    }
    
    
    
}







    
    

//
//
