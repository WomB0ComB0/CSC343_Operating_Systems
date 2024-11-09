Assume we have a 64bit machine with 16Terabytes of RAM. Page size=4KB

**Q1-How many memory frames do we have?**

Answer=

1KB=2<sup>10</sup> hence 4K page size is = 2<sup>10</sup>x4 = 2<sup>10</sup>x2<sup>2</sup>= 2<sup>12</sup>

1TB= 2<sup>40</sup> hence 16TB=2<sup>40</sup>x16= 2<sup>40</sup>x2<sup>4</sup>= 2<sup>44</sup>

Ram size/ Frame size = 2<sup>44</sup> / 2<sup>12</sup> = 2<sup>32</sup> is the total number of frames in the memory

**Q2-How many bits do we need for displacement in a page ?**

Page=4KB = 2<sup>10</sup>x4= 2<sup>10</sup>x2<sup>2</sup>=2<sup>12</sup> hence we need 12 bits to represent a displacement

**Q3- Assume it takes 36 bits to index into a page table. (this is the p)**

How many number of entires in the page table ?

Then you will have 2<sup>36</sup> pages the virtual memory space.

Each entry is address to the frame. The address is 64 bits (p+d).

**Q4-Page Table total size ?**

word size=64bits = 8bytes=2<sup>3</sup>

We have 2<sup>36</sup> pages and each entry is 8 bytes = 2<sup>3</sup>bytes (p+d).

Total page table size = 2<sup>36</sup>x 2<sup>3</sup> = 2<sup>39</sup> bytes

**Q5-In terms of 4K pages**

2<sup>39</sup> / 2<sup>12</sup> = 2<sup>27</sup> number of 4K pages in the page table.

No longer internal and external fragmentation

Drawback: Single page table can be huge.

1GB= 2<sup>30</sup> 2<sup>39</sup>= 2<sup>30</sup>x 2<sup>9</sup>= 1GBx512= 512GB

Solution multi level paging
</rewrite_this>