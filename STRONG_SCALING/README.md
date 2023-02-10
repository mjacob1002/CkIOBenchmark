These results are measured by starting a wall timer just before the CProxy_Reader::ckNew call and then taking the end time after every reader hits the reduction.That is, these times
don't include the initial setup of the read session where CkIO buffers the data from disk.
