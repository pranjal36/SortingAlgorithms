nums = [7, 4, 5, 1, 3, 2];

for (let i = 0; i < nums.length; i++) {
  setTimeout(() => {
    console.log(nums[i]);
  }, nums[i]);
}
