using AutoMapper;
using Hotel_WPF.BL.Interfaces;
using Hotel_WPF.DAL.Entities;
using Hotel_WPF.DAL.Interfaces;
using Hotel_WPF.TL.DTO;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.BL.Classes
{
    internal class ReservationServicelogic : IEntityLogic<ReservationServiceDTO>
    {
        private readonly IHotelRepository<ReservationService> _repository;
        private readonly IMapper _mapper;

        public ReservationServicelogic(IHotelRepository<ReservationService> repository, IMapper mapper)
        {
            _repository = repository;
            _mapper = mapper;
        }

        public async Task Add(ReservationServiceDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<ReservationService>(entityDTO);
                await _repository.Add(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task<List<ReservationServiceDTO>> GetAll()
        {
            var results = _mapper.Map<List<ReservationServiceDTO>>(await _repository.GetAll());
            return results;
        }


        public async Task Remove(ReservationServiceDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                await _repository.Delete(entityDTO.IdReservation);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }



        public async Task Update(ReservationServiceDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<ReservationService>(entityDTO);
                await _repository.Update(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        Task<ReservationServiceDTO> IEntityLogic<ReservationServiceDTO>.GetByName(string name)
        {
            throw new NotImplementedException();
        }
    }
}
