#ifndef STAN_RNG_OVERRIDE_HPP
#define STAN_RNG_OVERRIDE_HPP

#include <boost/random/additive_combine.hpp>
#include <boost/random/mixmax.hpp>
#include <stan/services/util/create_rng.hpp>

namespace stan {
  using curr_rng_t = decltype(stan::services::util::create_rng(0,0));
  // RNG type prior to v2.35 is boost::ecuyer1988, after is boost::random::mixmax
  // The stan::rng_t typedef was introduced in v2.35,
  // so add a workaround for the 2.32 -> 2.36+ transition 
  using rng_t = std::conditional_t<std::is_same<curr_rng_t, boost::ecuyer1988>::value,
                                    boost::ecuyer1988, boost::random::mixmax>;
}

#endif
