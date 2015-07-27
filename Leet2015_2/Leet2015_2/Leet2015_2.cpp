// Leet2015.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Solution2.h"


using namespace std;
typedef std::numeric_limits< double > dbl;

int _tmain(int argc, _TCHAR* argv[])
{
	// Runtime begin marker start
	clock_t begin = clock();

//6/29/2015
	//Solution2::ReverseInteger::Main(); // Easy
	//Solution2::ReverseBits::Main(); // Easy
	//Solution2::ReverseWordsInAString::Main(); // Medium
	
//6/30/2015
	//Solution2::ReverseWordsInAStringII::Main(); // Medium
	//Solution2::ReverseLinkedList::Main(); // Easy
	//Solution2::ReverseLinkedListII::Main(); // Medium
	//Solution2::ReverseNodesInKGroup::Main();

//7/1/2015
	//Solution2::TwoSum::Main(); // Medium
	//Solution2::TwoSumII::Main(); // Medium	
	//Solution2::TwoSumIII::Main(); // Easy -----------> potential better way of doing it?
	//Solution2::ThreeSum::Main(); // Medium
	//Solution2::ThreeSumClosest::Main(); // Medium

//7/2/2015
	//Solution2::FourSum::Main(); // Medium
	//Solution2::AddTwoNumbers::Main(); // Medium
	//Solution2::AddBinary::Main(); // Easy
	//Solution2::AddAndSearchWordDataStructureDesign::Main(); // Medium
	//Solution2::ImplementTrie::Main(); // Medium
	//Solution2::Anagrams::Main(); // Medium
	//Solution2::BalancedBinaryTree::Main(); // Easy
	//Solution2::BinaryTreeLevelOrderTraversal::Main();  // Easy
	//Solution2::BinaryTreeLevelOrderTraversalII::Main(); // Easy
	//Solution2::NumberOf1Bits::Main(); // Easy


//7/3/2015
	//Solution2::BasicCalculator::Main(); // Medium
	//Solution2::BasicCalculatorII::Main(); // Medium
	//Solution2::BinarySearchTreeIterator::Main(); // Medium
	//Solution2::BinaryTreeInorderTraversal::Main(); // Medium
	//Solution2::BinaryTreePreorderTraversal::Main(); // Easy
	//Solution2::BinaryTreeMaximumPathSum::Main(); // Medium  -----------------------> had some issues 
	//Solution2::BinaryTreeZigzagLevelOrderTraversal::Main();   // Medium
	//Solution2::BinaryTreeUpsideDown::Main(); // Medium
	//Solution2::BinaryTreePostorderTraversal::Main();  // Hard
	//Solution2::BinaryTreeRightSideView::Main(); // Medium
	//Solution2::BitwiseAndOfNumbersRange::Main(); // Medium -------------------------> had some issues
	//Solution2::Candy::Main(); // Hard
	//Solution2::ClimbingStairs::Main(); // Easy
	//Solution2::CloneGraph::Main(); // Medium
	//Solution2::Combinations::Main(); // Medium
	//Solution2::CombinationSum::Main(); // Medium
	//Solution2::CombinationSumII::Main(); // Medium
	//Solution2::CombinationSumIII::Main(); // Medium
	//Solution2::CompareVersionNumbers::Main();
	//Solution2::ContainsDuplicate::Main(); // Easy
	//Solution2::ContainsDuplicateII::Main(); // Easy

//7/4/2015
	//Solution2::ContainsDuplicateIII::Main(); // Medium ----------------------------------> had some issues
	//Solution2::ContainerWithMostWater::Main(); // Medium
	//Solution2::ConstructBinaryTreeFromInorderAndPostorderTraversal::Main(); // Medium
	//Solution2::ConstructBinaryTreeFromPreorderAndInorderTraversal::Main(); // Medium
	//Solution2::ConvertSortedArrayToBinarySearchTree::Main(); // Medium
	//Solution2::ConvertSortedListToBinarySearchTree::Main(); // Medium ----------------------> had some issues
	//Solution2::CopyListWithRandomPointer::Main(); // Hard
	//Solution2::CountAndSay::Main();  // Easy
	//Solution2::CountCompleteTreeNodes::Main();  // Medium ======================================> has better solve
	//Solution2::CountPrimes::Main();  // Easy ----------------------------------> had some issues
	//Solution2::CourseSchedule::Main();  // Medium
	//Solution2::CourseScheduleII::Main(); // Medium
	//Solution2::DecodeWays::Main(); // Medium
	//Solution2::DistinctSubsequences::Main(); // Hard
	//Solution2::DivideTwoIntegers::Main(); // Medium


//7/5/2015
	//Solution2::MergeSortedArray::Main(); // Easy
	//Solution2::DungeonGame::Main(); // Hard ----------------------------------> had some issues
	//Solution2::EditDistance::Main(); // Hard
	//Solution2::EvaluateReversePolishNotation::Main();  // Medium
	//Solution2::ExcelSheetColumnNumber::Main();  // Easy
	//Solution2::ExcelSheetColumnTitle::Main();	//Easy
	//Solution2::FactorialTrailingZeroes::Main(); // Easy
	//Solution2::FindMinimumInRotatedSortedArray::Main(); //Medium ----------------------------------> had some issues
	//Solution2::FindMinimumInRotatedSortedArrayII::Main(); // Hard
	//Solution2::FirstMissingPositive::Main(); // Hard
	//Solution2::FlattenBinaryTreeToLinkedList::Main(); // Medium
	//Solution2::FractionToRecurringDecimal::Main(); //Medium


// 7/6/2015
	//Solution2::GasStation::Main(); // Medium
	//Solution2::GenerateParentheses::Main(); // Medium
	//Solution2::GrayCode::Main(); // Medium
	//Solution2::HappyNumber::Main(); // Easy
	//Solution2::HouseRobber::Main(); // Easy
	//Solution2::HouseRobberII::Main(); // Medium
	//Solution2::ImplementStackUsingQueues::Main(); // Medium
	//Solution2::FindPeakElement::Main(); //Medium  ----------------------------------> had some issues
	//Solution2::InsertInterval::Main(); // Hard

// 7/7/2015
	//Solution2::InsertionSortList::Main(); //Medium
	//Solution2::IntegerToRoman::Main(); // Medium
	//Solution2::RomanToInteger::Main(); // Easy
	//Solution2::InterleavingString::Main(); // Hard
	//Solution2::IntersectionOfTwoLinkedLists::Main(); // Easy
	//Solution2::InvertBinaryTree::Main(); // Easy
	//Solution2::IsomorphicStrings::Main(); // Easy
	//Solution2::JumpGame::Main(); // Medium
	//Solution2::JumpGameII::Main(); // Hard ----------------------------------> had some issues
	//Solution2::KthLargestElementInAnArray::Main(); // Medium ----------------------------------> had some issues


// 7/8/2015
	//Solution2::LargestNumber::Main(); // Medium ----------------------------------> had some issues
	//Solution2::LargestRectangleInHistogram::Main(); //Hard
	//Solution2::LengthOfLastWord::Main(); // Easy
	//Solution2::LetterCombinationsOfAPhoneNumber::Main(); // Medium
	//Solution2::LinkedListCycle::Main(); // Medium
	//Solution2::LinkedListCycleII::Main(); // Medium ----------------------------------> had some issues
	//Solution2::LongestCommonPrefix::Main(); // Easy
	//Solution2::LongestConsecutiveSequence::Main(); //Hard
	//Solution2::LongestPalindromicSubString::Main(); // Medium ----------------------------------> had better way of doing it
	//Solution2::LongestSubstringWithAtMostTwoDistinctCharacters::Main(); //Hard ----------------------------------> may have better way to do it
	//Solution2::LongestSubStringWithoutRepeatingCharacters::Main(); // Medium


// 7/9/2015
	//Solution2::LongestValidParentheses::Main(); // Hard
	//Solution2::LRUCacheEntry::Main(); // Hard ----------------------------------> had some issues
	//Solution2::MajorityElement::Main(); // Easy
	//Solution2::MaximalRectangle::Main(); // Hard
	//Solution2::MaximalSquare::Main(); // Medium

// 7/10/2015
	//Solution2::MaximumDepthOfBinaryTree::Main(); // Easy
	//Solution2::MinimumDepthOfBinaryTree::Main(); // Easy
	//Solution2::MaximumGap::Main(); // Hard----------------------------------> had some issues(forgot the algo)
	//Solution2::MaximumProductSubarray::Main(); // Medium ----------------------------------> had some issues
	//Solution2::MaximumSubarray::Main(); // Medium
	//Solution2::MaxPointsOnALine::Main(); // Hard
	//Solution2::MergeTwoSortedLists::Main(); // Easy

// 7/11/2015
	//Solution2::MergeKSortedLists::Main();	 // Hard ----------------------------------> found a better way of doing it
	//Solution2::MergeIntervals::Main(); // Hard
	//Solution2::MedianOfTwoSortedArrays::Main(); // Hard----------------------------------> need some work still

// 7/12/2015
	//Solution2::MinimumPathSum::Main(); // Medium
	//Solution2::MinimumSizeSubarraySum::Main(); // Medium
	//Solution2::MinimumWindowSubstring::Main(); // Hard
	//Solution2::MinStack::Main(); // Easy
	//Solution2::MissingRanges::Main(); // Medium
	//Solution2::NumberOfIslands::Main(); // Medium
	//Solution2::MultiplyStrings::Main(); // Medium

// 7/13/2015
	//Solution2::NextPermutation::Main(); // Medium
	//Solution2::NQueens::Main(); // Hard
	//Solution2::NQueensII::Main(); // Hard
	//Solution2::OneEditDistance::Main(); // Medium ----------------------------------> had some issues
	//Solution2::PalindromeNumber::Main(); // Easy ----------------------------------> not any extra space?
	//Solution2::PalindromePartitioning::Main(); // Medium
	//Solution2::PalindromePartitioningII::Main(); // Hard ----------------------------------> had some issues
	//Solution2::PartitionList::Main(); // Medium
	//Solution2::PascalsTriangle::Main(); // Easy
	//Solution2::PascalsTriangleII::Main(); // Easy

// 7/14/2015
	//Solution2::PathSum::Main(); // Easy  ----------------------------------> had some issues
	//Solution2::PathSumII::Main(); // Medium
	//Solution2::Permutation::Main(); // Medium
	//Solution2::PermutationII::Main(); // Hard
	//Solution2::PlusOne::Main(); // Easy

// 7/15/2015
	//Solution2::PermutationSequence::Main(); // Medium ----------------------------------> had some issues, completely forget how to do it
	//Solution2::PopulatingNextRightPointersInEachNode::Main(); // Medium
	//Solution2::PopulatingNextRightPointersInEachNodeII::Main(); // Hard

// 7/16/2015
	//Solution2::Pow::Main(); // Medium
	//Solution2::ReadNCharactersGivenRead4::Main(); // Easy ----------------------------------> had some issues
	//Solution2::ReadNCharactersGivenRead4II::Main(); // Hard
	//Solution2::RecoverBinarySearchTree::Main(); // Hard----------------------------------> had some issues. completely  forgot how to do it. Need to look at iterative way to do it too.
	//Solution2::RectangleArea::Main(); // Easy
	//Solution2::RemoveElement::Main(); // Easy
	//Solution2::RemoveDuplicatesFromSortedArray::Main(); // Easy

// 7/17/2015
	//Solution2::RemoveDuplicatesFromSortedArrayII::Main(); // Medium
	//Solution2::RemoveDuplicatesfromSortedList::Main(); // Easy
	//Solution2::RemoveDuplicatesFromSortedListII::Main(); // Medium
	//Solution2::RemoveLinkedListElements::Main(); // Easy
	//Solution2::RemoveNthNodeFromEndOfList::Main(); // Easy
	//Solution2::ReorderList::Main(); // Medium
	//Solution2::RepeatedDNASequences::Main(); // Medium
	//Solution2::RotateArray::Main(); // Easy
	//Solution2::RestoreIPAddresses::Main(); // Medium
	//Solution2::RotateList::Main(); // Medium

// 7/18/2015
	//Solution2::BestTimeToBuyAndSellStock::Main(); // Medium
	//Solution2::BestTimeToBuyAndSellStockII::Main(); // Medium
	//Solution2::BestTimeToBuyAndSellStockIII::Main(); // Hard
	//Solution2::BestTimeToBuyAndSellStockIV::Main(); // Hard----------------------------------> had some issues, completely forget the solve
	//Solution2::RegularExpressionMatching::Main(); // Hard ----------------------------------> had some issues
	//Solution2::WildcardMatching::Main(); // Hard----------------------------------> had some issues
	//Solution2::ValidParentheses::Main(); // Easy
	//Solution2::SymmetricTree::Main(); // Easy
	//Solution2::DeleteNodeInALinkedList::Main(); // Easy
	//Solution2::PalindromeLinkedList::Main(); // Easy

// 7/19/2015
	//Solution2::ImplementStrStr::Main(); // Easy----------------------------------> had some issues, forget KMP
	//Solution2::ShortestPalindrome::Main(); // Hard ---------------------------------> had some issues, completely forget the solve
	//Solution2::ScrambleString::Main();  // Hard
	//Solution2::SearchInRotatedSortedArray::Main(); // Hard
	//Solution2::SearchInRotatedSortedArrayII::Main(); // Medium
	//Solution2::SearchA2DMatrix::Main(); // Medium	
	//Solution2::SearchForARange::Main(); // Medium	
	//Solution2::SearchInsertionPosition::Main(); // Medium	
	//Solution2::SetMatrixZeroes::Main(); // Medium	
	//Solution2::SimplifyPath::Main(); // Medium	

// 7/20/2015
	//Solution2::PowerOfTwo::Main(); // Easy	
	//Solution2::ProductOfArrayExceptSelf::Main(); // Medium	
	//Solution2::RotateImage::Main(); // Medium	
	//Solution2::StringToInteger::Main(); // Easy
	//Solution2::SingleNumber::Main(); // Medium	
	//Solution2::SingleNumberII::Main(); // Medium ----------------------------------> had some issues
	//Solution2::SortColors::Main(); // Medium	
	//Solution2::SortList::Main(); // Medium	
	//Solution2::SpiralMatrix::Main(); // Medium	----------------------------------> had some issues
	//Solution2::SpiralMatrixII::Main(); // Medium	
	//Solution2::Subsets::Main(); // Medium	
	//Solution2::SubsetsII::Main(); // Medium	

// 7/21/2015
	//Solution2::SummaryRanges::Main(); // Easy
	//Solution2::SumRootToLeafNumbers::Main(); // Medium	
	//Solution2::SwapNodesInPairs::Main(); // Medium	
	//Solution2::SurroundedRegions::Main(); // Medium	----------------------------------> had some issues
	//Solution2::UniquePaths::Main(); // Medium
	//Solution2::UniquePathsII::Main();// Medium
	//Solution2::ValidPalindrome::Main // Easy
	//Solution2::ValidSudoku::Main(); // Easy----------------------------------> had some issues


// 7/22/2015
	//Solution2::TextJustification::Main(); // Hard ----------------------------------> had some issues. Emgod. Took 1.5 hours
	//Solution2::LowestCommonAncestorOfABinarySearchTree::Main(); // Easy


// 7/23/2015
	//Solution2::SubstringWithConcatenationOfAllWords::Main(); // Hard----------------------------------> has a more complicated but faster solve, jumped over that.
	//Solution2::SudokuSolver::Main(); // Hard----------------------------------> had some issues. Found a much simpler and faster way to do this. Yay
	//Solution2::Triangle::Main(); // Medium
	//Solution2::TrappingRainWater::Main(); // Hard --------------------------------> Found a second 1pass O(n) solution
	//Solution2::ImplementQueueUsingStacks::Main(); //Easy
	//Solution2::UniqueBinarySearchTrees::Main(); // Medium
	//Solution2::UniqueBinarySearchTreesII::Main();  // Medium----------------------------------> had some issues.
	//Solution2::WordBreak::Main();
	//Solution2::WordBreakII::Main();----------------------------------> had some issues.
	//Solution2::ValidateBinarySearchTree::Main();  // Medium


// 7/24/2015
	//Solution2::WordSearch::Main(); // Medium ----------------------------------> had some issues. Found a faster solve
	//Solution2::WordSearchII::Main(); // Hard
	//Solution2::WordLadder::Main(); // Medium
	//Solution2::LowestCommonAncestorOfABinaryTree::Main(); // Medium
	//Solution2::ZigZagConversion::Main(); // Easy


// 7/25/2015
	//Solution2::WordLadderII::Main(); // Hard
	//Solution2::TheSkylineProblem::Main(); // Hard ---------------------------------> had some issues, completely forget the solve


// 7/26/2015
	//Solution2::SlidingWindowMaximum::Main(); // Hard
	//Solution2::SearchA2DMatrixII::Main(); // Medium
	//Solution2::MajorityElementII::Main(); // Medium
	//Solution2::KthSmallestElementInABST::Main(); // Medium
	//Solution2::ValidNumber::Main(); // Hard
	//Solution2::Sqrt::Main // Medium
Solution2::NumberOfDigitOne::Main(); // Medium




	// Runtime end marker
	clock_t end = clock();
	double elapsed_time_in_millisecond = double(end - begin) / double(CLOCKS_PER_SEC / 1000.0);

	// End program routine
	cout.precision(dbl::digits10);
	cout << "\n\nYour program total runtime is: " << elapsed_time_in_millisecond << "ms";
	cout << "\n\nPress enter key to exit ...\n\n";
	cin.get();
	return 0;
}

