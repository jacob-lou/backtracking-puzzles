#include <gtest/gtest.h>
#include "schedwork.h"

static bool valid(const AvailabilityMatrix& avail, size_t dailyNeed, size_t maxShifts, const DailySchedule& sched) {
  size_t days = avail.size();
  size_t workers = avail[0].size();
  std::vector<size_t> shifts(workers, 0);

  if(sched.size() != days) return false;
  for(size_t d=0; d<days; d++){
    if(sched[d].size() != dailyNeed) return false;
    for(size_t s=0; s<dailyNeed; s++){
      Worker_T w = sched[d][s];
      if(w >= workers) return false;
      if(!avail[d][w]) return false;
      // no duplicates per day
      for(size_t t=0; t<s; t++) if(sched[d][t]==w) return false;
      shifts[w]++;
      if(shifts[w] > maxShifts) return false;
    }
  }
  return true;
}

TEST(Schedwork, SmallFeasible) {
  AvailabilityMatrix avail = {
    {1,1,0},
    {1,0,1},
    {0,1,1}
  };
  DailySchedule sched;
  bool ok = schedule(avail, /*dailyNeed*/2, /*maxShifts*/2, sched);
  EXPECT_TRUE(ok);
  EXPECT_TRUE(valid(avail, 2, 2, sched));
}
